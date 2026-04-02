#pragma once
#include"HashTable.h"
namespace my
{
	template<class K,class Hash= HashFunc<K>>
	class unoredered_set
	{
		struct KeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		
	public:
		typedef typename HashTable_bucket::HashTable< K, const K, KeyOfT, Hash>::Iterator iterator;
		typedef typename HashTable_bucket::HashTable<K, const K, KeyOfT, Hash>::ConstIterator const_iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		const_iterator begin() const
		{
			return _ht.begin();
		}
		const_iterator end() const
		{
			return _ht.end();
		}
		bool insert(const K& key)
		{
			return _ht.Insert(key).second;
		}  
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}
		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}
		
	private:
		HashTable_bucket::HashTable< K,const K,KeyOfT,Hash> _ht;
	};
}

