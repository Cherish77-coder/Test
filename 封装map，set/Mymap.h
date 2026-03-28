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
		bool insert(const pair<K,V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<K, V>, mapKOfT> _t;
	};
}