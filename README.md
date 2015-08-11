
##Motivation
I've always wanted to understand how basic indexing work in Oracle.

There are two main indexes B-Tree and Hash. 

B-Tree allows us to to search for substring of the key. 

  `select * from test where name like ="A%";`

while Hash only allows us to search for an exact match.

  `select * from test where name = "ABC";`


In this code, I have two requirements , search for an exact match and best match. Exact match is fastest when an hashmap is used while a best match requires a sorted data structure.



##Code design
Design was influenced by www.fuzzy.cz/en/tags/indexes/

Theory is from the book File Structures Using C++ by Venugopal, K.R.

| Index Type        | STL                   | Remarks            |
| ---------------- |:----------------------:| ------------------:|
|PrimaryTreeIndex  | std::map               |Key must be unique  |
|SecondaryTreeIndex| std::multimap          |Allows duplicate key|
|PrimaryHashIndex  | std::unordered_map     |Key must be unique  |                    |
|SecondaryHashIndex| std::unordered_multimap|Allows duplicate key|


##Performance Test
1 million records in Index with single thread search

Primary Tree Index Exact Match Time taken = 177.93ms for 50000 transactions

Primary Tree Index Exact Match TPS = 281009

Primary Hash Index Exact Match Time taken = 43.296ms for 50000 transactions

Primary Hash Index Exact Match TPS = 1154841

Primary Tree Index Best Match Time taken = 191.299ms for 50000 transactions

Primary Tree Index Best Match TPS = 261370

Primary Tree MultiIndex(10000 maps)  Exact Match Time taken = 108.672ms for 50000 transactions

Primary Tree MultiIndex Exact Match TPS = 460100

