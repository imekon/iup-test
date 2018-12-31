#include "GenericDialog.h"

GenericDialog::GenericDialog()
{
	dialog = nullptr;
}

GenericDialog::~GenericDialog()
{
	if (dialog)
		IupDestroy(dialog);
}

bool GenericDialog::showModal()
{
	IupPopup(dialog, IUP_CENTER, IUP_CENTER);

	return true;
}