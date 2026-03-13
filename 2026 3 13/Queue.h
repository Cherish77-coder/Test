namespace my
{
	template<class T,class Container=list<T>>
	class queue
	{
	public:
		queue(){}
		bool empty()
		{
			return _con.size() == 0;
		}
		const T& top() const
		{
			return _con.back();
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& front()
		{
			return _con.front();
		}
		size_t size()
		{
			return _con.size();
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
	private:
		Container _con;
	};
}