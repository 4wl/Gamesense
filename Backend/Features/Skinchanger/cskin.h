//#pragma once
//
//#include "../../Include/GlobalIncludes.h"
//#include "../../SDK/CBaseEntity.h"
//#include "../../SDK/CViewSetup.h"
//namespace Proxies
//{
//	void nSequence(const CRecvProxyData* pData, void* pStruct, void* pOut);
//}
//extern RecvVarProxyFn o_nSequence;
//struct Item_t
//{
//	constexpr Item_t(const char* model, const char* icon = nullptr) : model(model), icon(icon) {}
//
//	const char* model;
//	const char* icon;
//};
//struct WeaponName_t
//{
//	constexpr WeaponName_t(int definition_index, const char* name) : definition_index(definition_index), name(name) {}
//
//	int definition_index = 0;
//	const char* name = nullptr;
//};
//struct EconomyItem_t
//{
//	void UpdateValues()
//	{
//		definition_vector_index = definition_vector_index < int(k_weapon_names.size()) ? definition_vector_index : k_weapon_names.size() - 1;
//		definition_index = k_weapon_names.at(definition_vector_index).definition_index;
//
//		entity_quality_vector_index = entity_quality_vector_index < int(k_quality_names.size()) ? entity_quality_vector_index : k_quality_names.size() - 1;
//		entity_quality_index = k_quality_names.at(entity_quality_vector_index).index;
//
//		if (definition_index == GLOVE_T_SIDE && !k_gloves.empty())
//		{
//			paint_kit_vector_index = paint_kit_vector_index < int(k_gloves.size()) ? paint_kit_vector_index : k_gloves.size() - 1;
//			paint_kit_index = k_gloves.at(paint_kit_vector_index).id;
//
//			definition_override_vector_index = definition_override_vector_index < int(k_glove_names.size()) ? definition_override_vector_index : k_glove_names.size() - 1;
//			definition_override_index = k_glove_names.at(definition_override_vector_index).definition_index;
//		}
//		else if (!k_skins.empty())
//		{
//			paint_kit_vector_index = paint_kit_vector_index < int(k_skins.size()) ? paint_kit_vector_index : k_skins.size() - 1;
//			paint_kit_index = k_skins.at(paint_kit_vector_index).id;
//
//			definition_override_vector_index = definition_override_vector_index < int(k_knife_names.size()) ? definition_override_vector_index : k_knife_names.size() - 1;
//			definition_override_index = k_knife_names.at(definition_override_vector_index).definition_index;
//		}
//	}
//
//	void UpdateIds()
//	{
//		definition_vector_index = std::find_if(k_weapon_names.begin(), k_weapon_names.end(), [this](const WeaponName_t& x)
//		{
//			return this->definition_index == x.definition_index;
//		}) - k_weapon_names.begin();
//
//		entity_quality_vector_index = find_if(k_quality_names.begin(), k_quality_names.end(), [this](const QualityName_t& x)
//		{
//			return this->entity_quality_index == x.index;
//		}) - k_quality_names.begin();
//
//		const auto& skin_set = definition_index == GLOVE_T_SIDE ? k_gloves : k_skins;
//
//		paint_kit_vector_index = std::find_if(skin_set.begin(), skin_set.end(), [this](const Kit_t& x)
//		{
//			return this->paint_kit_index == x.id;
//		}) - skin_set.begin();
//
//		const auto& override_set = definition_index == GLOVE_T_SIDE ? k_glove_names : k_knife_names;
//
//		definition_override_vector_index = find_if(override_set.begin(), override_set.end(), [this](const WeaponName_t& x)
//		{
//			return this->definition_override_index == x.definition_index;
//		}) - override_set.begin();
//	}
//
//	char name[32] = "Default";
//	bool enabled = false;
//	int definition_vector_index = 0;
//	int definition_index = 1;
//	int entity_quality_vector_index = 0;
//	int entity_quality_index = 0;
//	int paint_kit_vector_index = 0;
//	int paint_kit_index = 0;
//	int definition_override_vector_index = 0;
//	int definition_override_index = 0;
//	int seed = 0;
//	int stat_trak = 1337;
//	float wear = FLT_MIN;
//	char custom_name[32] = "Nasa";
//};
//
//class Skinchanger : public singleton<Skinchanger>
//{
//
//public:
//
//	void Work();
//
//	void ForceItemUpdates();
//
//	void SaveSkins();
//	void LoadSkins();
//
//	EconomyItem_t* GetByDefinitionIndex(int definition_index);
//
//	std::vector<EconomyItem_t>& GetItems() { return m_items; }
//
//	std::unordered_map<std::string, std::string>& GetIconOverrideMap() { return m_icon_overrides; }
//	const char* GetIconOverride(const std::string& original) { return m_icon_overrides.count(original) ? m_icon_overrides.at(original).c_str() : nullptr; }
//
//	bool bForceFullUpdate = true;
//
//private:
//
//	std::vector<EconomyItem_t> m_items;
//	std::unordered_map<std::string, std::string> m_icon_overrides;
//};