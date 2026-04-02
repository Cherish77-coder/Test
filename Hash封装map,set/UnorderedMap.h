#pragma once
namespace my
{
	template<class K,class V,class Hash=HashFunc<K>>
	class unordered_map
	{
	public:
		struct KeyOfT;
	    typedef typename HashTable_bucket::HashTable<K, pair<const K, V>, KeyOfT, Hash>::Iterator iterator;
		typedef typename HashTable_bucket::HashTable<K, pair<const K, V>, KeyOfT, Hash>::ConstIterator const_iterator;
		struct KeyOfT
		{
			const K& operator()(const pair<const K, V>& kv) const 
			{
				return kv.first;
			}
		};
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert({ key,V() });
			return ret.first->second;
		}
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _ht.Insert(kv);
		}
		bool erase(const pair<const K, V>& kv)
		{
			_ht.Erase(kv);
		}
		iterator find(const K& key)
		{
			_ht.Find(key);
		}
	private:
		HashTable_bucket::HashTable<K, pair<const K, V>, KeyOfT, Hash> _ht;

	};
}