#include "json.hpp"
namespace fs = std::filesystem;

nlohmann::json cfgjsonobj;

fs::path cfg_path = fs::current_path() / "minty";
std::ofstream settings_fileO(cfg_path, std::ios_base::app);
std::ifstream settings_fileI(cfg_path);