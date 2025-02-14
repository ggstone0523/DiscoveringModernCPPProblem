#include <iostream>
#include <string>

class person
{
	public:
		explicit person(const std::string& name) : name{name} {}
		explicit person() {}

		void set_name(const std::string& n) { name = n; }
		std::string get_name() const { return name; }
		virtual void all_info() const
		{ std::cout << "[person] My name is " << name << std::endl; }
	private:
		std::string name;
};

class student : public virtual person
{
	public:
		student(const std::string& name, const std::string& passed)
			: person{name}, passed{passed} {}
		virtual void all_info() const override {
			person::all_info();
			std::cout << "    I passed the following grades: " 
				  << passed << std::endl;
		}
	protected:
		student(const std::string& passed) : passed{passed} {}
		void my_info() const {
			std::cout << "    I passed the following grades: " 
				  << passed << std::endl;
		}
	private:
		std::string passed;
};

class mathmatician : public virtual person
{
	public:
		mathmatician(const std::string& name, const std::string& proved)
			: person{name}, proved{proved} {}
		virtual void all_info() const override {
			person::all_info();
			std::cout << "    I proved: " << proved << std::endl;
		}
	protected:
		mathmatician(const std::string& proved) : proved{proved} {}
		void my_info() const {
			std::cout << "    I proved: " << proved << std::endl;
		}
	private:
		std::string proved;
};

class math_student : public student, public mathmatician
{
	public:
		math_student(const std::string& name, 
			     const std::string& passed, 
			     const std::string& proved)
			: person{name}, student{passed}, mathmatician{proved} {}
		virtual void all_info() const override {
			student::all_info();
			mathmatician::my_info();
		}
};
