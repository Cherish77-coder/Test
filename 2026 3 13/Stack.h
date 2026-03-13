namespace my
{
	template<class T,class Container=vector<T>>
	class stack
	{
	public:
		stack()
		{ }
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