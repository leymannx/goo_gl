# Google URL Shortener (goo_gl)
## Custom Drupal 7 module to implement the goo.gl URL Shortener
### Please feel free to fork or add comments if you wish something to get implemented or think something could be made better.

On creation of a new node the URL path alias will be shortened via goo.gl.
If no URL path alias is available, the logic simply falls back to take Drupal's internal system path (node/123).

Since URL shortening with goo.gl is nearly impossible as unregistered user (limited use for unregistered users) I made entering a Google API key mandatory.
Get a Google API key at [https://console.developers.google.com/]()

Installation:
* Download and install module.
* Go to `admin/config/search/goo_gl` and enter your Google API key.
* Go to a content type settings form (e.g. `admin/structure/types/manage/article`) and enable goo_gl in the available vertical tabs form.
* Add a new node and have a goo.gl short URL generated automatically, visible in the vertical tabs and available from `$node->goo_gl_url`.

TODO:
* Offer statistics
