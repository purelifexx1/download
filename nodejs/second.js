var Struct = require("struct");
var realtime_data = Struct().word16Sbe('solar_voltage').word16Sbe('solar_current').word32Sle('solar_power').word16Sbe('bat_voltage').word16Sbe('bat_current').word32Sle('bat_power')
								.word16Sbe('load_voltage').word16Sbe('load_current').word32Sle('load_power').word16Sbe('bat_temp').word16Sbe('temp_in').word16Sbe('bat_percent');
var statistic_data = Struct().word16Sbe('max_pv_vol_today').word16Sbe('min_pv_vol_today').word16Sbe('max_bat_vol_today').word16Sbe('min_bat_vol_today').word32Sle('con_energy_today')
								.word32Sle('con_energy_month').word32Sle('con_energy_year').word32Sle('total_con_energy').word32Sle('gen_energy_today')
								.word32Sle('gen_energy_month').word32Sle('gen_energy_year').word32Sle('total_gen_energy');
realtime_data.allocate();
statistic_data.allocate();
var realtime_union_buf = realtime_data.buffer();
var statistic_union_buf = statistic_data.buffer();
var struct_statistic_data = statistic_data.fields;
var struct_realtime_data = realtime_data.fields;
const monthNames = ["January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
];

function get_realtime(){
	return {
		sec: new Date().getSeconds(),
		min: new Date().getMinutes(),
		hour: new Date().getHours(),
		day: new Date().getDate(),
		month: new Date().getMonth(),
		year: new Date().getFullYear()
	};
}
var coils_status = {
	onoff_charging: false,
	output_control: false,
	manual_control: false,
	default_control: false,
	load_testmode: false,
	onoff_load: false
};
module.exports = {

	realtime_send: function(io){
		io.sockets.emit("realtime_data", struct_realtime_data);
		var status_value;
		var count_shift = 0;
		Objects.keys(coils_status).forEach(function(element){
			if (((status_value >> count_shift++) & 1) == 1)
				coils_status[element] = true;
			else
				coils_status[element] = false;			
		});
		io.sockets.emit("control_status_data", coils_status);
	},
	statistic_send: function(io){
		io.sockets.emit("statistic_data", struct_statistic_data);
	},
	control_status_send: function(io, status){
		var count_shift = 0;
		Objects.keys(coils_status).forEach(function(element){
			if (((status >> count_shift++) & 1) == 1)
				coils_status[element] = true;
			else
				coils_status[element] = false;			
		});
		io.sockets.emit("control_status_data", coils_status);
	},
	update_server: function(main_branch){
		var real_time = get_realtime();
		var date = real_time.day + " " + monthNames[real_time.month] + " " + real_time.year;
		var time = real_time.hour + ":" + real_time.min + ":" + real_time.sec;
		var date_branch = main_branch.child(date + " at " + time);
		date_branch.update(struct_realtime_data);
		console.log(date + " at " + time);
	}

};

module.exports.realtime_buf = realtime_union_buf;

module.exports.statistic_buf = statistic_union_buf;


