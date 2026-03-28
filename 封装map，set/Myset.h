#pragma once
#include"RBtree.h"
namespace my
{
	template<class K>
	struct setIterator
	{
		RBTreeNode<K> ret;
	};
	template<class K>
	class set
	{
		struct KOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K,const K,KOfT>::Iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			iterator ret(_t.end());
			return ret;
		}
		
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		 RBTree<K, const K, KOfT> _t;
	};
}