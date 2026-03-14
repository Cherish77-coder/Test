namespace my
{
	template<class T>
	class Less
	{
	public:
		bool operator()( const T& a,const  T& b) 
		{
			return a < b;
		}
	};
	template<class T, class Container = vector<T>,class cmp=Less<T>>
	class priority_queue
	{
		//cmp cmp();
		public:	
			cmp scmp;
		bool empty()
		{
			return _con.size() == 0;
		}
		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}
		void pop()
		{
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		size_t size()
		{
			return _con.size();
		}
		const T& top()
		{
			return _con.front();
		}
		void AdjustDown( int parent)
		{
			//Less<T> fun;
			int child = parent * 2 + 1;
			while (child+1 < _con.size())
			{
				if (child + 1 < size()&& scmp(_con[child+1],_con[child]))
				{
					child = child + 1;
				}
				if (scmp(_con[child],_con[parent]))
				{
					std::swap(_con[child], _con[parent]);
				}
				parent = child;
				child = parent * 2 + 1;
			}
		}
		void AdjustUp(int child)
		{
			int parent=0;
			//Less<T> fun;
			while (child > 0)
			{
				parent = (child - 1) / 2;
				if (scmp(_con[child],_con[parent]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
			
		}
	private:
		Container _con;
	};
	
	//template<Contai>
	
}
