#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("default"), _signed(0), _gradeSign(150), _gradeExec(150) {}

Form::Form(std::string name, int gradeSign, int gradeExec) 
: _name(name)
, _signed(0)
, _gradeSign(gradeSign)
, _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1) throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150) throw GradeTooLowException();
}

Form::Form(const Form &cpy)
: _name(cpy._name)
, _signed(cpy._signed)
, _gradeSign(cpy._gradeSign)
, _gradeExec(cpy._gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1) throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150) throw GradeTooLowException();
}

Form& Form::operator=(Form const &rhs)
{
    if (this != &rhs)
	{
		_signed = rhs._signed;
    }
    return (*this);
}

Form::~Form(){}

int Form::getGradeSign(){
	return _gradeSign;
}

int Form::getGradeExec(){
	return _gradeExec;
}

std::string Form::getName(){
	return _name;
}

bool Form::getSigned(){
	return _signed;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}


std::ostream& operator<<(std::ostream &out, Form &form)
{
	out << form.getName() << " with grade " << form.getGradeSign();
	if (form.getSigned())
		out << " is signed,";
	else
		out << " is not signed,";
	out << " exec grade is " << form.getGradeExec();
	
	return out;
}