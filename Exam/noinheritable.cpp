class NonInheritable {
public:
    static NonInheritable createInstance() {
        return NonInheritable();
    }
    
    // other public methods here

private:
    NonInheritable() {}  // private constructor

    // disallow copying and assigning
    NonInheritable(const NonInheritable&) = delete;
    NonInheritable& operator=(const NonInheritable&) = delete;
};

class Pochodna : public NonInheritable{};  // This will generate an error

int main() {
    auto a = NonInheritable::createInstance();
    //Pochodna b;  // Uncommenting this line will cause a compilation error
}
