#include<iostream>
#include<exception>
#include<string>

class CustomException : public std::exception
{
private:
    std::string message;
public:
    CustomException(const std::string& message) : message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class MathException : public CustomException
{
public:
    MathException(const std::string& message) : CustomException(message){}
};

class MemoryException : public CustomException
{
public:
    MemoryException(const std::string& message) : CustomException(message) {}
};

class FileException : public CustomException
{
public:
    FileException(const std::string& message) : CustomException(message) {}
};

int main()
{
    try
    {
   
        throw MathException("Division by zero");

       
        throw MemoryException("Out of memory");

        throw FileException("File not found");
    }
    catch (const CustomException& ex)
    {
        
        std::cerr << "CustomException: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}