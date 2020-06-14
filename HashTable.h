#pragma once
#include "Item.h"
#include <iostream>

template <class T>
class HashTable
{
private:
	int _size;
	vector<Item<T>*> items;

public:
	HashTable(int size)
	{
		items.reserve(size);
		for (int i = 0; i < size; i++)
		{
			auto S = new Item<T>(i);
			items.push_back(S);
		}
		_size = size;
	}

	void Add(T item)
	{
		int key = GetHash(item);
		items[key]->Nodes.push_back(item);
	}

	void Remove(T item)
	{
		items[GetHash(item)]->Nodes.erase(items[GetHash(item)]->Nodes.begin());
	}

	bool Search(T item)
	{
		return find(items[GetHash(item)].Nodes.begin(), items[GetHash(item)].Nodes.end(), item) != items[GetHash(item)].Nodes.end();
	}

	int GetHash(T item)
	{
		auto key = item.GetHashCode();
		return key % _size;
	}

	vector<Item<T>*> GetList()
	{
		return items;
	}

	void ShowTable()
	{
		for (int i = 0; i < _size; i++)
		{
			if (items[i]->Nodes.size() > 0)
			{
				std::cout << "\n" << i;
				for (int j = 0; j < items[i]->Nodes.size(); j++)
				{
					std::cout << "\n\t" << items[i]->Nodes[j].ToString();
				}
			}
		}
	}



};

