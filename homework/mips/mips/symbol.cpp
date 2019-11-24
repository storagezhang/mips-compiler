﻿#include "symbol.h"

Symbol::Symbol() {
	this->array_length_ = 0;
	this->reg_number_ = 0;
	this->sp_offer_ = 0;
	this->kind_ = KindSymbol::CONST;
	this->type_ = TypeSymbol::INT;
	this->is_use_ = false;
};

void Symbol::SetProperty(string name, KindSymbol kind, TypeSymbol type) {
	this->name_ = name;
	this->kind_ = kind;
	this->type_ = type;
}

string Symbol::name() {
	return this->name_;
}

KindSymbol Symbol::kind() {
	return this->kind_;
}

TypeSymbol Symbol::type() {
	return this->type_;
}

void Symbol::AddParameter(char c) {
	this->parameter_.push_back(c);
}

string Symbol::parameter() {
	return this->parameter_;
}

int Symbol::GetParameterCount() {
	return this->parameter_.length();
}

void Symbol::set_const_value(string constValue) {
	this->const_value_ = constValue;
}

string Symbol::const_value() {
	return this->const_value_;
}

void Symbol::set_array_length(int arrayLength) {
	this->array_length_ = arrayLength;
}

int Symbol::array_length() {
	return this->array_length_;
}

void Symbol::set_reg_number(int regNumber) {
	this->reg_number_ = regNumber;
}

int Symbol::reg_number() {
	return this->reg_number_;
}

void Symbol::set_sp_offer(int spOffer) {
	this->sp_offer_ = spOffer;
}

int Symbol::sp_offer() {
	return this->sp_offer_;
}

void Symbol::set_is_use(bool isUse) {
	this->is_use_ = isUse;
}

bool Symbol::is_use() {
	return is_use_;
}