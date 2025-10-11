#include <iostream>
#include "clsBankClient.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "String.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsLogin.h"
using namespace std;




int main()
{
	while (true)
	{
		if (!clsLogin::ShowLoginScreen())
			break;
	}
	


	return 0;
}
