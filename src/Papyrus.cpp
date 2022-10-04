#include "Papyrus.h"

using namespace RE;

namespace Papyrus {
    const std::string PapyrusClass = "EventSpoofer";
	const auto kError = RE::BSScript::Internal::VirtualMachine::Severity::kError;
	
	bool SpoofEvent(RE::VMTypeID type, BSFixedString* eventName, const void* self, RE::BSScript::IFunctionArguments* args...)
	{
		auto handle = SkyrimVM::GetSingleton()->handlePolicy.GetHandleForObject(type, self);
		if (handle != 0) {
			SkyrimVM::GetSingleton()->SendAndRelayEvent(handle, eventName, args, nullptr);
			return true;
		}
		return false;
	}

	bool SpoofOnActivate(VM* vm, StackID id, StaticFunctionTag*, TESObjectREFR* self, TESObjectREFR* akActivator)
	{
		if (self == nullptr) {
			vm->TraceStack("Error: source cannot be null", id, kError);
			return false;
		}
		if (akActivator == nullptr) {
			vm->TraceStack("Error: akActivator cannot be null", id, kError);
			return false;
		}

		BSFixedString eventName = "OnActivate";
		return SpoofEvent(static_cast<VMTypeID>(self->FORMTYPE), &eventName, self, RE::MakeFunctionArguments(std::move(akActivator)));
	}

	bool SpoofOnAttachedToCell(VM* vm, StackID id, StaticFunctionTag*, TESObjectREFR* self)
	{
		if (self == nullptr) {
			vm->TraceStack("Error: source cannot be null", id, kError);
			return false;
		}

		BSFixedString eventName = "OnAttachedToCell";
		return SpoofEvent(static_cast<VMTypeID>(self->FORMTYPE), &eventName, self, RE::MakeFunctionArguments());
	}

	bool SpoofOnCellAttach(VM* vm, StackID id, StaticFunctionTag*, TESObjectREFR* self)
	{
		if (self == nullptr) {
			vm->TraceStack("Error: source cannot be null", id, kError);
			return false;
		}

		BSFixedString eventName = "OnCellAttach";
		return SpoofEvent(static_cast<VMTypeID>(self->FORMTYPE), &eventName, self, RE::MakeFunctionArguments());
	}

	bool SpoofOnCellDetach(VM* vm, StackID id, StaticFunctionTag*, TESObjectREFR* self)
	{
		if (self == nullptr) {
			vm->TraceStack("Error: source cannot be null", id, kError);
			return false;
		}

		BSFixedString eventName = "OnCellDetach";
		return SpoofEvent(static_cast<VMTypeID>(self->FORMTYPE), &eventName, self, RE::MakeFunctionArguments());
	}

	bool SpoofOnCellLoad(VM* vm, StackID id, StaticFunctionTag*, TESObjectREFR* self)
	{
		if (self == nullptr) {
			vm->TraceStack("Error: source cannot be null", id, kError);
			return false;
		}

		BSFixedString eventName = "OnCellLoad";
		return SpoofEvent(static_cast<VMTypeID>(self->FORMTYPE), &eventName, self, RE::MakeFunctionArguments());
	}

	bool SpoofOnVampireFeed(VM* vm, StackID id, StaticFunctionTag*, Actor* self, Actor* akTarget)
	{
		if (self == nullptr) {
			vm->TraceStack("Error: source cannot be null", id, kError);
			return false;
		}
		if (akTarget == nullptr) {
			vm->TraceStack("Error: akTarget cannot be null", id, kError);
			return false;
		}

		BSFixedString eventName = "OnVampireFeed";
		return SpoofEvent(static_cast<VMTypeID>(self->FORMTYPE), &eventName, self, RE::MakeFunctionArguments(std::move(akTarget)));
	}

    bool Bind(VM* a_vm) {
        if (!a_vm) {
            logger::critical("couldn't get VM State"sv);
            return false;
        }

        logger::info("{:*^30}", "FUNCTIONS"sv);

		a_vm->RegisterFunction("SpoofOnActivate"sv, PapyrusClass, SpoofOnActivate, true);
		logger::info("Registered SpoofOnActivate");

		a_vm->RegisterFunction("SpoofOnAttachedToCell"sv, PapyrusClass, SpoofOnAttachedToCell, true);
		logger::info("Registered SpoofOnAttachedToCell");

		a_vm->RegisterFunction("SpoofOnCellAttach"sv, PapyrusClass, SpoofOnCellAttach, true);
		logger::info("Registered SpoofOnCellAttach");

		a_vm->RegisterFunction("SpoofOnCellDetach"sv, PapyrusClass, SpoofOnCellDetach, true);
		logger::info("Registered SpoofOnCellDetach");

		a_vm->RegisterFunction("SpoofOnCellLoad"sv, PapyrusClass, SpoofOnCellLoad, true);
		logger::info("Registered SpoofOnCellLoad");

		a_vm->RegisterFunction("SpoofOnVampireFeed"sv, PapyrusClass, SpoofOnVampireFeed, true);
		logger::info("Registered SpoofOnVampireFeed");

        return true;
    }
}  // namespace Papyrus
