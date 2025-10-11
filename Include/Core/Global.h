#pragma once

#include <iostream>
#include "clsUser.h"

clsUser CurrentUser = clsUser::Find("", "");

static bool _CheckAccessRights(clsUser::enPermessions permession)
{
    if (!CurrentUser.CheckAccessPermession(permession))
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\t\t\t\t\t Access Denied! Contact Your Admin";
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        return false;
    }
    else
        return true;
}