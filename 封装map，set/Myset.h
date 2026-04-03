#pragma once
#include"RBtree.h"
namespace my
{
	//template<class K>
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
		typedef typename RBTree<K, const K, KOfT>::ConstIterator const_iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			iterator ret(_t.end());
			return ret;
		}
		const_iterator cbegin() const
		{
			return _t.begin() ;
		}
		const_iterator cend() const
		{
			const_iterator ret(_t.end());
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