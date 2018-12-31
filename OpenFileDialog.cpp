#include "OpenFileDialog.h"

OpenFileDialog::OpenFileDialog(const char *filter)
{
	dialog = IupFileDlg();

	IupSetAttribute(dialog, "DIALOGTYPE", "OPEN");
	IupSetAttribute(dialog, "EXTFILTER", filter);
}

bool OpenFileDialog::showModal()
{
	if (!GenericDialog::showModal())
		return false;

	if (IupGetInt(dialog, "STATUS") == -1)
		return false;

	filename = IupGetAttribute(dialog, "VALUE");
	
	return true;
}
