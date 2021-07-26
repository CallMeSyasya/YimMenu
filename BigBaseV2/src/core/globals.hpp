#pragma once
#include "data/player_struct.hpp"
#include "enums.hpp"

#ifndef GLOBALS_H
#define GLOBALS_H

using namespace big;
struct globals {
	nlohmann::json default_options;
	nlohmann::json options;

	struct tunables {
		bool disable_phone = false;
		bool no_idle_kick = false;
	};

	struct player {
		int character_slot = 1;
		int set_level = 130;
		bool spectating = false;
	};

	struct protections {
		bool bounty = true;
		bool ceo_ban = true;
		bool ceo_kick = true;
		bool ceo_money = true;
		bool clear_wanted_level = true;
		bool fake_deposit = true;
		bool force_mission = true;
		bool force_teleport = true;
		bool gta_banner = true;
		bool personal_vehicle_destroyed = true;
		bool remote_off_radar = true;
		bool send_to_cutscene = true;
		bool send_to_island = true;
		bool sound_spam = true;
		bool spectate = true;
		bool transaction_error = true;
		bool vehicle_kick = true;
	};

	struct self {
		struct frame_flags {
			bool explosive_ammo = false;
			bool explosive_melee = false;
			bool fire_ammo = false;
			bool super_jump = false;
		};

		bool godmode = false;
		bool off_radar = false;
		bool noclip = false;
		bool no_ragdoll = false;

		frame_flags frame_flags{};
	};

	struct vehicle {
		bool horn_boost = false;
		SpeedoMeter speedo_meter = SpeedoMeter::DISABLED;
	};

	struct weapons {
		CustomWeapon custom_weapon = CustomWeapon::NONE;
		char vehicle_gun_model[12] = "bus";
	};

	struct window {
		bool handling = false;
		bool log = false;
		bool main = true;
		bool users = true;
		bool player = false;

		int x;
		int y;
	};

	int friend_count = 0;
	int player_count = 0;
	CPlayer players[32];
	CPlayer selected_player;

	tunables tunables{};
	player player{};
	protections protections{};
	self self{};
	vehicle vehicle{};
	weapons weapons{};
	window window{};

	void from_json(const nlohmann::json& j)
	{
		this->protections.bounty = j["protections"]["bounty"];
		this->protections.ceo_ban = j["protections"]["ceo_ban"];
		this->protections.ceo_kick = j["protections"]["ceo_kick"];
		this->protections.ceo_money = j["protections"]["ceo_money"];
		this->protections.clear_wanted_level = j["protections"]["clear_wanted_level"];
		this->protections.fake_deposit = j["protections"]["fake_deposit"];
		this->protections.force_mission = j["protections"]["force_mission"];
		this->protections.force_teleport = j["protections"]["force_teleport"];
		this->protections.gta_banner = j["protections"]["gta_banner"];
		this->protections.personal_vehicle_destroyed = j["protections"]["personal_vehicle_destroyed"];
		this->protections.remote_off_radar = j["protections"]["remote_off_radar"];
		this->protections.send_to_cutscene = j["protections"]["send_to_cutscene"];
		this->protections.send_to_island = j["protections"]["send_to_island"];
		this->protections.sound_spam = j["protections"]["sound_spam"];
		this->protections.spectate = j["protections"]["spectate"];
		this->protections.transaction_error = j["protections"]["transaction_error"];
		this->protections.vehicle_kick = j["protections"]["vehicle_kick"];

		this->tunables.disable_phone = j["tunables"]["disable_phone"];
		this->tunables.no_idle_kick = j["tunables"]["no_idle_kick"];

		this->self.godmode = j["self"]["godmode"];
		this->self.off_radar = j["self"]["off_radar"];
		this->self.no_ragdoll = j["self"]["no_ragdoll"];

		this->self.frame_flags.explosive_ammo = j["self"]["frame_flags"]["explosive_ammo"];
		this->self.frame_flags.explosive_melee = j["self"]["frame_flags"]["explosive_melee"];
		this->self.frame_flags.fire_ammo = j["self"]["frame_flags"]["fire_ammo"];
		this->self.frame_flags.super_jump = j["self"]["frame_flags"]["super_jump"];

		this->vehicle.horn_boost = j["vehicle"]["horn_boost"];
		this->vehicle.speedo_meter = (SpeedoMeter)j["vehicle"]["speedo_meter"];

		this->weapons.custom_weapon = (CustomWeapon)j["weapons"]["custom_weapon"];

		this->window.handling = j["window"]["handling"];
		this->window.log = j["window"]["log"];
		this->window.main = j["window"]["main"];
		this->window.users = j["window"]["users"];
	}

	nlohmann::json to_json()
	{
		return nlohmann::json{
			{
				"protections", {
					{ "bounty", this->protections.bounty },
					{ "ceo_ban", this->protections.ceo_ban },
					{ "ceo_kick", this->protections.ceo_kick },
					{ "ceo_money", this->protections.ceo_money },
					{ "clear_wanted_level", this->protections.clear_wanted_level },
					{ "fake_deposit", this->protections.fake_deposit },
					{ "force_mission", this->protections.force_mission },
					{ "force_teleport", this->protections.force_teleport },
					{ "gta_banner", this->protections.gta_banner },
					{ "personal_vehicle_destroyed", this->protections.personal_vehicle_destroyed },
					{ "remote_off_radar", this->protections.remote_off_radar },
					{ "send_to_cutscene", this->protections.send_to_cutscene },
					{ "send_to_island", this->protections.send_to_island },
					{ "sound_spam", this->protections.sound_spam },
					{ "spectate", this->protections.spectate },
					{ "transaction_error", this->protections.transaction_error },
					{ "vehicle_kick", this->protections.vehicle_kick }
				}
			},
			{
				"tunables", {
					{ "disable_phone", this->tunables.disable_phone },
					{ "no_idle_kick", this->tunables.no_idle_kick }
				}
			},
			{
				"self", {
					{ "godmode", this->self.godmode },
					{ "off_radar", this->self.off_radar },
					{ "no_ragdoll", this->self.no_ragdoll },

					{
						"frame_flags", {
							{ "explosive_ammo", this->self.frame_flags.explosive_ammo },
							{ "explosive_melee", this->self.frame_flags.explosive_melee },
							{ "fire_ammo", this->self.frame_flags.fire_ammo },
							{ "super_jump", this->self.frame_flags.super_jump }
						}
					}
				}
			},
			{
				"vehicle", {
					{ "horn_boost", this->vehicle.horn_boost },
					{ "speedo_meter", (int)this->vehicle.speedo_meter }
				}
			},
			{
				"weapons", {
					{ "custom_weapon", (int)this->weapons.custom_weapon }
				}
			},
			{
				"window", {
					{ "handling", this->window.handling },
					{ "log", this->window.log },
					{ "main", this->window.main },
					{ "users", this->window.users }
				}
			}
		};
	}

	void attempt_save()
	{
		nlohmann::json& j = this->to_json();

		if (deep_compare(this->options, j, true))
			this->save();
	}

	bool load()
	{
		this->default_options = this->to_json();

		std::string settings_file = std::getenv("appdata");
		settings_file += this->settings_location;

		std::ifstream file(settings_file);

		if (!file.is_open())
		{
			this->write_default_config();

			file.open(settings_file);
		}

		try
		{
			file >> this->options;
		}
		catch (const std::exception&)
		{
			LOG(WARNING) << "Detected corrupt settings, writing default config...";

			this->write_default_config();

			return this->load();
		}

		bool should_save = this->deep_compare(this->options, this->default_options);

		this->from_json(this->options);

		if (should_save)
		{
			LOG(INFO) << "Updating settings.";
			save();
		}

		return true;
	}

private:
	const char* settings_location = "\\BigBaseV2\\settings.json";

	bool deep_compare(nlohmann::json& current_settings, const nlohmann::json& default_settings, bool compare_value = false)
	{
		bool should_save = false;

		for (auto& e : default_settings.items())
		{
			const std::string &key = e.key();

			if (current_settings.count(key) == 0 || (compare_value && current_settings[key] != e.value()))
			{
				current_settings[key] = e.value();

				should_save = true;
			}
			else if (current_settings[key].is_structured() && e.value().is_structured())
			{
				if (deep_compare(current_settings[key], e.value(), compare_value))
					should_save = true;
			}
			else if (!current_settings[key].is_structured() && e.value().is_structured()) {
				current_settings[key] = e.value();

				should_save = true;
			}
		}

		return should_save;
	}

	bool save()
	{
		std::string settings_file = std::getenv("appdata");
		settings_file += this->settings_location;

		std::ofstream file(settings_file, std::ios::out | std::ios::trunc);
		file << this->to_json().dump(4);
		file.close();

		return true;
	}

	bool write_default_config()
	{
		std::string settings_file = std::getenv("appdata");
		settings_file += this->settings_location;

		std::ofstream file(settings_file, std::ios::out);
		file << this->to_json().dump(4);
		file.close();

		return true;
	}
};

inline struct globals g;
#endif // !GLOBALS_H
