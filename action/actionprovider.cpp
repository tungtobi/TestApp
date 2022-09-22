#include "actionprovider.h"
#include "flux/action.h"
#include "flux/dispatcher.h"
#include "actionprovider.h"
#include "actiontype.h"

ActionProvider ActionProvider::mInstance;

ActionProvider* ActionProvider::getInstance()
{
    return &(ActionProvider::mInstance);
}

void ActionProvider::startApp()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ActionStart, QVariant()));
}

void ActionProvider::stopApp()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ActionStop, QVariant()));
}

void ActionProvider::resetApp()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ActionReset, QVariant()));
}

void ActionProvider::exitApplication()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ExitApplication, QVariant()));
}

inline int sum(int a, int b) {
    return a + b;
}
int Tritype(int i, int j, int k) {
	int trityp = 0;
	if (i < 0 || j < 0 || k < 0)
		return 3;
	if (i + j <= k || j + k <= i || k + i <= j)
		return 3;
	if (i == j)
		trityp = trityp + 1;
	if (i == k)
		trityp = trityp + 1;
	if (j == k)
		trityp = trityp + 1;
	if (trityp >= 2)
		trityp = 2;
	return trityp;
}


/*
Link: pathcrawler-online.
*/
int uninit_var(int a[3], int b[3]) {
	int i, k=0;

	for(i=0; i<2; i++) {
		if(a[i] == 0)
			return 0;

		if(a[i] != a[i+1])
			k = 0;
		else if(k == 2)
			return 0;

		while(b[k] != a[i])
			if(k == 2)
				return 0;
			else
				k++;
	}
	return 1;
}

