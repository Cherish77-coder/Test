#pragma once
#include"RBTree.h"
namespace my
{
	template<class K,class V>
	class map
	{
		struct mapKOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		V& operator[](const V& val)
		{
			pair<iterator, bool> ret = _t.Insert({ val,V() });
			return ret.first->second;
		}
		typedef typename RBTree<K, pair<const K, V>, mapKOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, mapKOfT>::ConstIterator const_iterator;
			bool insert(const pair<K,V>& kv)
		{
			return _t.Insert(kv).second;
		}
			iterator begin()
			{
				return _t.begin();
			}
			iterator end()
			{
				return _t.end();
			}
			const_iterator cbegin() const
			{
				return _t.begin();
			}
			const_iterator cend() const
			{
				return _t.end();
			}
	private:
		RBTree<K, pair<const K, V>, mapKOfT> _t;
	};
}