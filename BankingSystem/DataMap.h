#pragma once

// TODO Brad: implement properly, stubs needed for other things
template <class T>
class DataMap
{
public:
	DataMap(void);
	~DataMap(void);
	void Add(T* elem);
	void Add(T elem);
};

template<class T>
DataMap<T>::DataMap(void)
{
}

template<class T>
DataMap<T>::~DataMap(void)
{
}

template<class T>
void DataMap<T>::Add(T* elem)
{
}

template<class T>
void DataMap<T>::Add(T elem)
{
}

