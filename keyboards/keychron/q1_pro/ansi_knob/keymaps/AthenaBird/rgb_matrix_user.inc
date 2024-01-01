// Step 1,
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool_effect2)

// Step 2,
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e,g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < 14; i++) {
    rgb_matrix_set_color(i, 159, 0, 255);
  }
   for (uint8_t i = 14; i < 30; i++) {
    rgb_matrix_set_color(i, 232 , 0, 181);
  }

    for (uint8_t i = 30; i < 45; i++) {
    rgb_matrix_set_color(i, 255 , 0, 53);
  }

   for (uint8_t i = 45; i < 59; i++) {
    rgb_matrix_set_color(i, 255 , 15 , 0);
  }
    for (uint8_t i = 59; i < 72; i++) {
    rgb_matrix_set_color(i, 255 , 53, 0);
  }
    for (uint8_t i = 72; i < led_max; i++) {
    rgb_matrix_set_color(i, 255 , 72, 0);
  }

  return rgb_matrix_check_finished_leds(led_max);
}

// GRADIENT TIME!!
static bool my_cool_effect2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    double keymap[][2] = {
        {0, 0}, {18, 0}, {32, 0}, {47, 0}, {62, 0}, {80, 0}, {95, 0}, {109, 0}, {124, 0}, {142, 0}, {157, 0}, {172, 0}, {186, 0}, {205, 0}, {223, 0},
        {0, 14}, {14, 14}, {29, 14}, {43, 14}, {58, 14}, {73, 14}, {87, 14}, {102, 14}, {117, 14}, {131, 14}, {146, 14}, {161, 14}, {175, 14}, {197, 14}, {224, 14},
        {3, 26}, {21, 26}, {36, 26}, {51, 26}, {65, 26}, {80, 26}, {95, 26}, {109, 26}, {124, 26}, {139, 26}, {153, 26}, {168, 26}, {183, 26}, {201, 26}, {224, 26},
        {5, 37}, {25, 37}, {40, 37}, {54, 37}, {69, 37}, {84, 37}, {98, 37}, {113, 37}, {128, 37}, {142, 37}, {157, 37}, {172, 37}, {195, 37}, {224, 37},
        {9, 50}, {32, 50}, {47, 50}, {62, 50}, {76, 50}, {91, 50}, {106, 50}, {120, 50}, {135, 50}, {150, 50}, {164, 50}, {185, 50}, {209, 50},
        {1, 62}, {20, 62}, {38, 62}, {93, 62}, {146, 62}, {161, 62}, {176, 62}, {194, 62}, {209, 62}, {224, 62}
    };

    int keymap_len = sizeof(keymap) / sizeof(keymap[0]); 

    double grad_pts[] = {0, 0.5, 1};
    double grad[][3] = {
        {255, 255, 255},
        {67, 219, 255},
        {255, 255, 0}
    };

    double x_dir = 0;
    double y_dir = 1; 

    double p_0 = 10000;
    double p_1 = -10000;

    int yorx = 0; 
    if (y_dir > x_dir) {
        yorx = 1;
    }

    // New map
    // project keymap
    int (*projected_keymap)[2] = malloc(sizeof(int[keymap_len][2]));
    for (int i = 0; i < keymap_len; i++) {
        
        double xk = keymap[i][0];
        double yk = keymap[i][1];
        double xp = (x_dir * x_dir * xk + x_dir * y_dir * yk) / (x_dir * x_dir + y_dir * y_dir);
        double yp = ((x_dir * y_dir * xk) + (y_dir * y_dir * yk)) / (x_dir * x_dir + y_dir * y_dir);

        projected_keymap[i][0] = xp;
        projected_keymap[i][1] = yp;

        // find boundary
        if (projected_keymap[i][yorx] < p_0) {
            p_0 = projected_keymap[i][yorx];
        }
        if (projected_keymap[i][yorx] > p_1) {
            p_1 = projected_keymap[i][yorx];
        }
        
        /*
        if (y_dir > x_dir) {
            if (yp < p_0) {
                p_0 = yp;
            }
            if (yp > p_1) {
                p_1 = yp;
            }
        } else {
            if (xp < p_0) {
                p_0 = xp;
            }
            if (xp > p_1) {
                p_1 = xp;
            }
        }
        */
    }

    // what fraction are you on the line
    for (int i =0; i < keymap_len; i++) {
        double intp = 1 / (p_1-p_0) * (projected_keymap[i][yorx]-p_0);
        // interpolate over 
        int index = 0;
        double low = 0;
        double high = 0; 
        for (int i = 0; i < keymap_len; i++) {
            if (intp >= grad_pts[i]){
                low = grad_pts[i];
            }
                
            if (intp < grad_pts[i]){
                index = i;
                high = grad_pts[i];
                break;
            }
 
        }

        double *l_color = grad[index-1];
        double *h_color = grad[index];
        
        double R = (l_color[0] + (h_color[0] - l_color[0])/ (high - low) * (intp - low));
        double G = (l_color[1] + (h_color[1] - l_color[1])/ (high - low) * (intp - low));
        double B = (l_color[2] + (h_color[2] - l_color[2])/ (high - low) * (intp - low));

        // set RGB 
        rgb_matrix_set_color(i, R , G, B);
    }
        
    
    free(projected_keymap);
    return rgb_matrix_check_finished_leds(led_max);

}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
