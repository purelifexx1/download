const register_reference = {
    //realtime data
    "12544": "solar_voltage",
    "12545": "solar_current",
    "12546": "*solar_power",
    "12548": "bat_voltage",
    "12549": "bat_current",
    "12550": "*bat_power",
    "12556": "load_voltage",
    "12557": "load_current",
    "12558": "*load_power",
    "12560": "bat_temp",
    "12561": "temp_in",
    "12562": "$heat_sink_temp",
    "12570": "bat_percent",
    "12571": "remote_bat_temp",
    "12573": "bat_rated_voltage",


    //statistic data
    "13056": "max_pv_vol_today",
    "13057": "min_pv_vol_today",
    "13058": "max_bat_vol_today",
    "13059": "min_bat_vol_today",
    "13060": "*con_energy_today",
    "13062": "*con_energy_month",
    "13064": "*con_energy_year",
    "13066": "*total_con_energy",
    "13068": "*gen_energy_today",
    "13070": "*gen_energy_month",
    "13072": "*gen_energy_year",
    "13074": "*total_gen_energy",

    //some bat figure
    "13083": "*real_bat_current",
    "13085": "another_bat_temp",
    "13086": "ambient_temp",

    //coil status
    "2"    : "@load_control",
    "5"    : "@enable_test_mode",
    "6"    : "@force_load"
};
module.exports.reference_table = register_reference;