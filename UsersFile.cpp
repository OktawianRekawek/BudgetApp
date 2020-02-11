#include "UsersFile.h"

void UsersFile::saveUserInFile(User user){
    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getID());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(FILE_NAME);
}

vector<User> UsersFile::readUsersFromFile(){
    CMarkup xml;
    vector<User> users;
    User user;

    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
        return users;

    xml.FindElem("Users");
    xml.IntoElem();

    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        user.setID(atoi(MCD_2PCSZ(xml.GetData())));
        cout << "UserID: " << user.getID() << endl;
        xml.FindElem( "Login" );
        user.setLogin(xml.GetData());
        cout << "Login: " << user.getLogin()<< endl;
        xml.FindElem( "Password" );
        user.setPassword(xml.GetData());
        cout << "Password: " << user.getPassword()<< endl;
        xml.FindElem( "Name" );
        user.setName(xml.GetData());
        cout << "Name: " << user.getName()<< endl;
        xml.FindElem( "Surname" );
        user.setSurname(xml.GetData());
        cout << "Surname: " << user.getSurname()<< endl;
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}