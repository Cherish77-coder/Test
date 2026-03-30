#pragma once
#include<vector>
using namespace std;
enum State
{
	EMPTY,
	EXIT,
	ERASE
};
template<class K,class V>
struct Datatype
{
	pair<K, V> _kv;
	State _state = EMPTY;
};
template<class K, class V>
struct HashTable
{
public:
	HashTable(size_t size=11)
		:_tables(size)
		,_n(0)
	{}
	Datatype<K, V>* Find(const K& key)
	{
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state !=EMPTY)
		{
			if (_tables[hashi]._kv.first == key&& _tables[hash0]._state!=ERASE)
			{
				return &_tables[hashi];
			}
			hashi = (hash0 + i)%_tables.size();
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
			NewHt._tables.resize(2 * _tables.size());
			for (int i = 0; i < _tables.size(); ++i)
			{
				NewHt.Insert(_tables[i]._kv);
			}
			swap(_tables, NewHt._tables);
		}//À©ÈÝ
		size_t M = _tables.size();
		size_t hash0 = kv.first % M;
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state == EXIT)
		{
			hashi = (hash0 + i)%M;
			++i;
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
