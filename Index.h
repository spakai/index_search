#pragma once

#include "Table.h"

class Table;

class Index {
	public:
 		virtual void buildIndex(Table & table, int column)=0;
};
