#pragma once
#include<vector>
using namespace std;
inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}
template<class K>
struct HashFunc//转化为无符号整数
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
template<>
struct HashFunc<string>//转化为无符号整数
{
	size_t operator()(const string& key)
	{
		size_t ret = 0;
		for (auto e : key)
		{
			ret = ret * 131 + e;
		}
		return ret;
	}
};
namespace HashTable_bucket
{
	template<class K, class T, class KeyOfT, class Hash >
	class HashTable;
	template<class T>
	struct HashNode
	{
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr) {
		}
		T _data;
		HashNode<T>* _next = nullptr;
	};
	template<class K,class T,class Ptr,class Ref,class KeyOfT,class Hash >
	//关键词，类型，指针，引用，类型里面key的类型，hashi的转化
	 struct HTiterator//Hash的迭代器封装成一个类
	{
		 typedef HashNode<T> Node;
		 typedef HTiterator<K, T, Ptr, Ref, KeyOfT, Hash> Self;//自己的类型
		 Node* _node;
		 HashTable<K, T, KeyOfT, Hash>* _pht;//方便查找下一个桶的位置
		 //构造函数
		 HTiterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht)
			 :_node(node)
			 ,_pht(pht){ }
		 Self& operator++()
		 {
			 if (_node->_next)
			 {
				 _node = _node->_next;
			 }
			 else//_node->_next为空找下一个桶
			 {
				 Hash hash;
				 KeyOfT kot;
				 size_t hashi = hash(kot(_node->_data))% _pht->_tables.size();
				 ++hashi;
				 while (hashi<_pht->_tables.size())
				 {
					 if (_pht->_tables[hashi])
					 {
						 break;
					 }
					 else
					 {
						 ++hashi;
					 }
				 }
				 if (hashi == _pht->_tables.size())
				 {
					 _node = nullptr;
				 }
				 else
				 {
					 _node = _pht->_tables[hashi];
				 }
			 }
			 return *this;
		 }
		 bool operator!=(const Self& s) const
		 {
			 return s._node !=_node;
		 }
		 Ref& operator*()
		 {
			 //返回引用的数据类型
			 return _node->_data;
		 }
		 Ptr operator->()
		 {
			 //返回指针的引用拿来解引用
			 return &_node->_data;
		 }
	};
	template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{
		
	public:
		typedef HashNode<T> Node;
		typedef HTiterator<K, T, T*, T&, KeyOfT, Hash> Iterator;
		typedef HTiterator<K, T, const T*, const T&, KeyOfT, Hash> ConstIterator;
		template<class K, class T, class Ptr, class Ref, class KeyOfT, class Hash >
		friend struct HTiterator;//友元类声明
		Iterator begin()
		{
			if (_n == 0)
			{
				return end();
			}
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return Iterator(cur, this);
				}
			}
			return end();
		}
		ConstIterator begin() const
		{
			if (_n == 0)
			{
				return end();
			}
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return ConstIterator(cur, this);
				}
			}
			return end();
		}
		Iterator end() 
		{
			return Iterator(nullptr, this);
		}
		ConstIterator end() const
		{
			return ConstIterator(nullptr, this);
		}
		HashTable(size_t size = 11)
			:_tables(size)
			, _n(0)
		{
		}
		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				Node* next = nullptr;
				while (cur)
				{
					next = cur->_next;
					_tables[i] = next;
					delete cur;
					cur = next;
				}
			}
		}
		pair<Iterator,bool> Insert(const T& data)
		{
			KeyOfT kot;
			Iterator ret = Find(kot(data));
			if (ret._node)
			{
				return { ret,false };
			}
			Hash hash;
			if (_tables.size() == _n)//扩容
			{
				vector<Node*> NewTable(2 * _tables.size(), nullptr);
				for (auto& e : _tables)
				{
					Node* cur = e;
					while (cur)
					{
						Node* next = cur->_next;
						//头插
						size_t hashi = hash(kot(cur->_data)) % NewTable.size();
						cur->_next = NewTable[hashi];
						NewTable[hashi] = cur;
						cur = next;
					}
					e = nullptr;
				}
				swap(_tables, NewTable);
			}
			size_t hash0 = hash(kot(data)) % _tables.size();
			//头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hash0];
			_tables[hash0] = newnode;
			++_n;
			return {Iterator(newnode,this),true};
		}
		Iterator Find(const K& key)
		{
			Hash hash;
			KeyOfT kot;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return Iterator(cur,this);
				}
				else
				{
					cur = cur->_next;
				}
			}
			return Iterator(cur,this);
		}
		bool Erase(const K& key)
		{
			Hash hash;
			KeyOfT kot;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (cur == _tables[hashi])
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						if(prev)
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return  false;
		}
	private:
		vector<Node*> _tables;
		size_t _n;
	};
}
