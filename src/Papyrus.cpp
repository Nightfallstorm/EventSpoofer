#include "Papyrus.h"

using namespace RE;

namespace Papyrus {
    const std::string PapyrusClass = "EventSpoofer";

    bool Bind(VM* a_vm) {
        if (!a_vm) {
            logger::critical("couldn't get VM State"sv);
            return false;
        }

        logger::info("{:*^30}", "FUNCTIONS"sv);

        return true;
    }
}  // namespace Papyrus
