README.txt
==========

This module makes fetch whole YouTube channel as is. This means that YouTube
Playlists titles become taxonomy terms and YouTube Videos titles become nodes
tagged with proper taxonomy term (divided to same playlists as on YouTube).

Features: 
- YouTube Data API (v2). To quick start you just need YouTube Channel ID and
  your Application Key.
- Сontrol over what resources will be loaded to nodes.
- The ability to download all the channels or just recent videos. By cron as
  well.
- Extended watchdog information about which nodes were created either updated.

REQUIREMENTS
======================

This module requires YouTube Field module.
https://www.drupal.org/project/youtube

CONFIGURATION
======================

After typical installation check your YouTube credentials. Find your Channel ID 
in YouTube channel settings and register your app on YouTube to get Application Key.

Put it on first tab of setting page: 

/admin/config/media/yonodes

and press Save configuration.


USAGE
======================

Choose what type of assets do you need in NODE SETTINGS section.

Press "Fetch all playlists" button to get Playlists titles to 
corresponding taxonomy vocabulary.

Press "Fetch all videos" button to get all videos from channel.

You can get only recent videos by push on Fetch Last Videos button or 
enable cron for automatically updating.

Check Enable detail watchdog to have detailed reports about updated and 
new created nodes.

AUTHOR/MAINTAINER
======================
Yaremiy Roman
https://www.drupal.org/u/andrdrx
https://www.linkedin.com/in/roman-yaremiy-b3695b60
