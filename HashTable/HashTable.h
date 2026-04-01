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
//直接定址法
namespace HashTable_1
{
	enum State
	{
		EMPTY,
		EXIT,
		ERASE
	};
	template<class K, class V>
	struct Datatype
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>
	struct HashFunc<string>//特化模板
	{
		size_t operator()(const string& s)
		{
			size_t ret = 0;
			for (auto& e : s)
			{
				ret = ret * 131 + e;
			}
			return ret;
		}
	};
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable(size_t size = 11)
			:_tables(size)
			, _n(0)
		{
		}
		Datatype<K, V>* Find(const K& key)
		{
			size_t hash0 = Hash()(key) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._kv.first == key && _tables[hash0]._state != ERASE)
				{
					return &_tables[hashi];
				}
				hashi = (hash0 + i) % _tables.size();
				++i;
			}
			return nullptr;
		}
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable NewHt;
				NewHt._tables.resize(__stl_next_prime(_tables.size() + 1));
				for (int i = 0; i < _tables.size(); ++i)
				{
					NewHt.Insert(_tables[i]._kv);
				}
				swap(_tables, NewHt._tables);
			}//扩容
			size_t M = _tables.size();
			size_t hash0 = Hash()(kv.first) % M;
			//线性的探测
			size_t hashi = hash0;
			size_t i = 1;
			int flag = 1;
			/*while (_tables[hashi]._state == EXIT)
			{
				hashi = (hash0 + i)%M;
				++i;
			}*/
			//二次探测
			while (_tables[hashi]._state == EXIT)
			{
				hashi = (hash0 + i * i * flag) % M;
				if (flag == 1)
				{
					flag = -1;
				}
				else
				{
					flag = 1;
					++i;
				}
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIT;
			++_n;
			return true;
		}
		bool Erase(const K& key)
		{
			auto ret = Find(key);
			if (ret)
			{
				ret->_state = ERASE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}
	private:
		vector<Datatype<K, V>> _tables;
		size_t _n;
	};
}
//链接地址法
namespace HashTable_Bucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode(const pair<K,V>& kv)
			:_kv(kv)
			,_next(nullptr){}
		pair<K, V> _kv;
		HashNode<K,V>* _next = nullptr;
	};
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
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
		bool Insert(const pair<K,V>& kv)
		{
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
						size_t hashi = hash(cur->_kv.first) % NewTable.size();
						cur->_next = NewTable[hashi];
						NewTable[hashi] = cur;
						cur = next;
				    }
					e = nullptr;
				}
				swap(_tables, NewTable);
			}
			size_t hash0 = Hash()(kv.first) % _tables.size();
			//头插
			Node* newnode=new Node(kv);
			newnode->_next = _tables[hash0];
			_tables[hash0] = newnode;
			++_n;
			return true;
		}
		Node* Find(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key)%_tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first==key)
				{
					if (cur == _tables[hashi])
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
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
