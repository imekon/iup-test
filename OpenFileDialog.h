#pragma once

#include <string>

#include <iup.h>

#include "GenericDialog.h"

class OpenFileDialog : public GenericDialog
{
public:
	OpenFileDialog(const char *filter = "Text Files|*.txt|All Files|*.*|");
	bool showModal() override;
	std::string getFilename() const { return filename; }

private:
	std::string filename;
};