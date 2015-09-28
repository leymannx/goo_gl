# goo_gl
## Custom Drupal 7 module to implement the goo.gl URL Shortener

On creation of a new node the URL path alias will be shortened via goo.gl.
This module is implemented to run last on node creation, so that any URL path alias creating module will run first to have the URL path alias available for shortening.
If no URL path alias is available, it will simply fall back to take Drupal's internal system path (node/123).

Since URL shortening with goo.gl is nearly impossible as unregistered user (limited use for unregistered users) I made entering a Google API key mandatory.
Get a Google API key at https://console.developers.google.com/

For now the following will work:
* Install module.
* Go to `admin/config/search/goo_gl` and enter your Google API key.
* Go to a content type settings form (e.g. `admin/structure/types/manage/article`) and enable goo_gl in the available vertical tabs form.
* Add a new node and have a goo.gl short URL generated automatically, visible in the vertical tabs and available from `$node->goo_gl_url`.

TO DO:
* Should there be an option available to chose between alias path or internal path as source for shortening?
  Not really
* But maybe there should be some logic available what to happen if the URL alias gets renewed?
  But honestly I'ld guess users want to keep the current short URL and their statistics and simply apply a redirect from the old alias to the new alias manually.
* Offer an option to have the short URL automatically set as shortlink or canonical if that makes sense?

# Please feel free to fork or add comments if you wish something to get implemented or think something could be made better.