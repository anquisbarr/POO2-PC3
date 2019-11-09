#include "Repo.h"

int main() {
    cout << "Hello world!"<<endl;
    auto* repo = new Repo<Country>(",");
    return 0;
}