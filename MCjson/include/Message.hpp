#ifndef brigadier_HPP_Message
#define brigadier_HPP_Message

#include<iostream>

using std::string;

namespace brigadier {
	class Message {
	public:
		virtual string getString() = 0;
		virtual Message* clone() = 0; //return new obj
	};

	class LiteralMessage : public Message {
	private:
		string str;
	public:
		LiteralMessage(string& s);
		Message* clone() override;
		string getString() override;
		string toString();
	};

	inline LiteralMessage::LiteralMessage(string& s) { this->str = s; }

	Message* LiteralMessage::clone() {
		return new LiteralMessage(*this);
	}

	inline string LiteralMessage::getString() { return this->str; }

	inline string LiteralMessage::toString() { return this->str; }

}
#endif