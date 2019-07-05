#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

class HtmlBuilder;

class HtmlElement
{
    friend class HtmlBuilder;
 public:
    HtmlElement() {}

    HtmlElement(std::string name, std::string text)
        : name_(name),
          text_(text) {}

    virtual ~HtmlElement() {}

    static std::unique_ptr<HtmlBuilder> Create(std::string root_name) {
        return std::make_unique<HtmlBuilder>(root_name);
    }

    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string i(indent_size * indent, ' ');
        oss << i << "<" << name_ << ">" << std::endl;
        if (text_.size() > 0)
            oss << std::string(indent_size * (indent + 1), ' ') << text_ << std::endl;

        for (const auto &e : elements_)
            oss << e.str(indent + 1);

        oss << i << "</" << name_ << ">" << std::endl;
        return oss.str();
    }

 protected :
    std::string name_;
    std::string text_;
    std::vector<HtmlElement> elements_;
    const size_t indent_size = 2;
};

class HtmlBuilder
{
public:
    HtmlBuilder(std::string root_name) {
        root_.name_ = root_name;
    }

    virtual ~HtmlBuilder() {}

    HtmlBuilder &AddChild(std::string child_name, std::string child_text) {
        root_.elements_.emplace_back(child_name, child_text);
        return *this;
    }

    HtmlBuilder *AddChild2(std::string child_name, std::string child_text) {
        root_.elements_.emplace_back(child_name, child_text);
        return this;
    }

    operator HtmlElement() {
        return root_;
    }

    std::string str() {
        return root_.str();
    }

 private:
    HtmlElement root_;
};

int main(int argc, char const *argv[])
{
    HtmlElement element = HtmlBuilder("h").AddChild("p", "Hello").AddChild("p", "World");
    std::cout << element.str();

    HtmlElement element2 = HtmlElement::Create("h")->AddChild2("p", "Hello")->AddChild("p", "World");
    std::cout << element2.str();

    return 0;
}
