#pragma once

#include <iostream>

struct Article
{
	std::string		name;
	int				value;
};



class Command {
private:
	// Attributes
	int 				id;
	time_t				date;
	std::string			client;
	std::map<Article>	articles;

public:
	// Canonical Form
	Command(/* Data */);
	~Command();
	Command(const Command &other);
	Command &operator=(const Command &other);

/* Methode */
	void			addItem(Artice);
	const int		get_total_price();

};

Command::Command(int newId, std::string newClient) : id(newId), client(newClient) {
	date = time(NULL);
}

Command::~Command() {
	articles.clear();
}

Command::Command(const Command &other) {
	*this = other;
}

Command &Command::operator=(const Command &other) {
	if (this != &other) {
		id = other.id;
		date = other.date;
		client = other.client;
		articles = other.articles;
	}
	return *this;
}

/* Operator */

/* Getter / Setter */

/* Methode */
	void Command::addItem(Article) {
		
	}

