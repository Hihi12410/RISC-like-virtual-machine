What is SHWM?
SHWM (Simulated HardWare Module) is a loadable module interface, kinda like LKMS in Linux.
It works by establishing a flag and callback hook between the module and the module handler.
The module handler is a global singleton, while any number of modules can be loaded.
On startup, the handler requests the list of modules to be loaded, and a control module, that connects all the modules.
Module calls can be achieved with the module interrupt system, and passing flags to the module handler singleton.
The singleton handles InterPC/IntraPC on startup. Then modules can estabilish R/W systems between themselves.

---Interface compatibility---
Interface compatibility requires the following implementations
-DECLARE_SHWM
-IMPLEMENT_SHWM_R_INT
-IMPLEMENT_SHWM_P_FLAGS
-IMPLEMENT_SHWM_R_FLAGS
-IMPLEMENT_SHWM_H_INT
-IMPLEMENT_SHWM_REGISTER 
-IMPLEMENT_SHWM_UNREGISTER

For startup, the module handler has to get a valid .kinit file.
.kinit file should be structured this way:

start kinit
start kinclude
lib1
lib2
lib3
...
lib_n-1
lib_n
end kinclude

kbinhand lib_included_in_kinclude_bytecode_handler
kvideoconf "path_to_dotkvideoconf_file"
kvidhand lib_in_kinclude_video_transcriber

end kinit

.kvideoconf:

start kvideoconf

res_x 1920
res_y 1080
bits_per_pixel 8

end kvideoconf
