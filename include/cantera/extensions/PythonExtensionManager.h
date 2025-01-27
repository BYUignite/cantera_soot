//! @file PythonExtensionManager.h

#ifndef CT_PYTHONEXTENSIONMANAGER_H
#define CT_PYTHONEXTENSIONMANAGER_H

// This file is part of Cantera. See License.txt in the top-level directory or
// at https://cantera.org/license.txt for license and copyright information.

#include "cantera/base/ExtensionManager.h"

namespace Cantera
{

//! Class for managing user-defined Cantera extensions written in Python
//!
//! Handles Python initialization if the main application is not the Python interpreter.
//!
//! Imports a user-specified module, which must be on the Python path and registers
//! user-defined classes that are marked with the `@extension` decorator. See the
//! documentation for
//! <a href="../../sphinx/html/cython/utilities.html#cantera.extension">`@extension`</a>
//! in the Python documentation for more information.
//!
//! @since New in Cantera 3.0
class PythonExtensionManager : public ExtensionManager
{
public:
    PythonExtensionManager();
    virtual void registerRateBuilders(const std::string& extensionName) override;

    //! Function called from Cython to register an ExtensibleRate implementation
    static void registerPythonRateBuilder(const std::string& moduleName,
        const std::string& className, const std::string& rateName);

private:
    static bool s_imported;
};

}

#endif
