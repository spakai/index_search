class TreeIndex: public Index {
	public:
 		virtual void buildIndex(Table & table, int column)=0;

	private:
		std::map<std::string, std::vector<int>> items;
};
