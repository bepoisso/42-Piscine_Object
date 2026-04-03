#pragma once

#include <cstddef>
#include <mutex>
#include <vector>

template <typename T>
class SingletonList
{
public:
	static SingletonList& getInstance()
	{
		static SingletonList instance;
		return instance;
	}

	SingletonList(const SingletonList&) = delete;
	SingletonList& operator=(const SingletonList&) = delete;

	void add(const T& value)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		_items.push_back(value);
	}

	bool get(std::size_t index, T& outValue) const
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (index >= _items.size())
			return false;
		outValue = _items[index];
		return true;
	}

	std::vector<T> getAll() const
	{
		std::lock_guard<std::mutex> lock(_mutex);
		return _items;
	}

	std::size_t size() const
	{
		std::lock_guard<std::mutex> lock(_mutex);
		return _items.size();
	}

private:
	SingletonList() {}

	mutable std::mutex _mutex;
	std::vector<T> _items;
};
