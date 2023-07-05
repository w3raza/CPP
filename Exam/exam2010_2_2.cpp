#include <vector>
#include <iostream>

using std::cout;

struct Object{
    virtual const char * print() const = 0; 
};

struct ConsoleObject : Object{
    virtual const char * print() const override = 0; 
};

struct ConsoleLine : ConsoleObject{
    const char * print() const override{
        return "Console Line";
    }
};

struct ConsoleText : ConsoleObject{
    const char * print() const override{
        return "Console Text";
    }
};

struct GuiObject : Object{
    virtual const char * print() const override = 0; 
};

struct GuiLine : GuiObject{
    const char * print() const override{
        return "Gui Line";
    }
};

struct GuiText : GuiObject{
    const char * print() const override{
        return "Gui Text";
    }
};

int main()
{
    std::vector<Object*> objs;
    ConsoleObject*console0=new ConsoleLine();
    ConsoleObject*console1=new ConsoleText();
    GuiObject* gui0=new GuiLine();
    GuiObject* gui1=new GuiText();
    objs.push_back(console0); objs.push_back(console1);
    objs.push_back(gui0); objs.push_back(gui1);
    for(unsigned i=0; i !=objs.size();i++)
    cout<< objs[i]->print() << ",";
}
// wynik działania:
// Console Line,Console Text,Gui Line,Gui Text,

// int main()
// {
// std::vector<Object*> objs;
// ConsoleObject*console0=new ConsoleLine();
// ConsoleObject*console1=new ConsoleText();
// GuiObject* gui0=new GuiLine();
// GuiObject* gui1=new GuiText();
// objs.push_back(console0); objs.push_back(console1);
// objs.push_back(gui0); objs.push_back(gui1);
// for(unsigned i=0; i !=objs.size();i++)
// cout<<objs[i]->print()",";
// wynik działania:
// Console Line,Console Text,Gui Line,Gui Text,