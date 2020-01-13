# include "unknow_project.h"

t_sound_engine	create_t_sound_engine()
{
	t_sound_engine	result;

	result.music = load_music();
	result.sounds = load_sounds();
	return (result);
}

t_sound_engine	*initialize_t_sound_engine()
{
	t_sound_engine	*result;

	if (!(result = (t_sound_engine	*)malloc(sizeof(t_sound_engine))))
		return (NULL);
	*result = create_t_sound_engine();
	return (result);
}

void			delete_t_sound_engine(t_sound_engine dest)
{
	free(dest.music);
	free(dest.sounds);
}

void			free_t_sound_engine(t_sound_engine *dest)
{
	delete_t_sound_engine(*dest);
	free(dest);
}

Mix_Music	**load_music()
{
	Mix_Music 	**music;
	int nb_music;
	int i;
	nb_music = 1;

	if (!(music = (Mix_Music**)malloc(sizeof(Mix_Music*) * nb_music)))
		error_exit(66, "Couldn't malloc array of music (load_music)");
	music[0] = Mix_LoadMUS("ressources/assets/sounds/IG_theme.wav");
	i = 0;
	while(i < nb_music)
		if (!music[i++])
		{
			ft_putstr("Mix_LoadWAV: ");
			ft_putstr(Mix_GetError());
			write(1, "\n", 1);
		}
	return (music);
}

Mix_Chunk	**load_sounds()
{
	Mix_Chunk 	**sounds;
	int nb_sounds;
	int i;

	nb_sounds = 22;
	if (!(sounds = (Mix_Chunk**)malloc(sizeof(Mix_Chunk*) * nb_sounds)))
		error_exit(66, "Couldn't malloc array of sounds (load_sounds)");
	sounds[0] = Mix_LoadWAV("ressources/assets/sounds/click.wav");
	sounds[1] = Mix_LoadWAV("ressources/assets/sounds/jump.wav");
	sounds[2] = Mix_LoadWAV("ressources/assets/sounds/jetpack_ignition.wav");
	sounds[3] = Mix_LoadWAV("ressources/assets/sounds/jetpack_on.wav");
	sounds[4] = Mix_LoadWAV("ressources/assets/sounds/jetpack_no_fuel.wav");
	sounds[5] = Mix_LoadWAV("ressources/assets/sounds/jetpack_stopping.wav");
	sounds[6] = Mix_LoadWAV("ressources/assets/sounds/land.wav");
	sounds[7] = Mix_LoadWAV("ressources/assets/sounds/pistol.wav");
	sounds[8] = Mix_LoadWAV("ressources/assets/sounds/ar.wav");
	sounds[9] = Mix_LoadWAV("ressources/assets/sounds/rifle.wav");
	sounds[10] = Mix_LoadWAV("ressources/assets/sounds/shotgun.wav");
	sounds[11] = Mix_LoadWAV("ressources/assets/sounds/rpg.wav");
	sounds[12] = Mix_LoadWAV("ressources/assets/sounds/door_open.wav");
	sounds[13] = Mix_LoadWAV("ressources/assets/sounds/door_close.wav");
	sounds[14] = Mix_LoadWAV("ressources/assets/sounds/explosion.wav");
	sounds[15] = Mix_LoadWAV("ressources/assets/sounds/death.wav");
	sounds[16] = Mix_LoadWAV("ressources/assets/sounds/hit1.wav");
	sounds[17] = Mix_LoadWAV("ressources/assets/sounds/hit2.wav");
	sounds[18] = Mix_LoadWAV("ressources/assets/sounds/pistol_reload.wav");
	sounds[19] = Mix_LoadWAV("ressources/assets/sounds/ar_reload.wav");
	sounds[20] = Mix_LoadWAV("ressources/assets/sounds/rifle_reload.wav");
	sounds[21] = Mix_LoadWAV("ressources/assets/sounds/shotgun_reload.wav");
	sounds[22] = Mix_LoadWAV("ressources/assets/sounds/pickup.wav");
	i = 0;
	while(i < nb_sounds)
		if (!sounds[i++])
		{
			ft_putstr("Mix_LoadWAV: ");
			ft_putstr(Mix_GetError());
			write(1, "\n", 1);
		}
	return (sounds);
}