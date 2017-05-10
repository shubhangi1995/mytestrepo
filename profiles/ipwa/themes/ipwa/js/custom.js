jQuery(document).ready(function(){

    //Detection for external links
    hostname = new RegExp(location.host);
    // Act on each link
    jQuery('a[href]').each(function(){
        // Store current link's url
        var url = jQuery(this).prop("href");

        // Test if current host (domain) is in it
        if(!hostname.test(url)){
            // a link that does not contain the current host i.e external link
            jQuery(this).addClass('external-link').append("<span class='ext'></span>");
            jQuery(this).attr('target', '_blank');
        }
    });
	
	
	jQuery('#views-exposed-form-aktuelles-page select').select2({
        minimumResultsForSearch: Infinity
	}); 
	
	
	jQuery("input:radio").each(function(){
  if(jQuery(this).is(':checked'))
  {
	jQuery(this).parent("label").css('border-bottom', '2px solid #e74712');
  }
}); 

// scrollbar

jQuery('.page-aktuelles select').select2().on("select2:open", function(){
 jQuery('.page-aktuelles .select2-results').addClass("simplebar");
 jQuery('.page-aktuelles .select2-results').simplebar();
});
	
//search
	
    //open popup
    jQuery('.search-icon').on('click', function(event){
        event.preventDefault();
        jQuery('.block-ipwa-search').addClass('is-visible');
    });
    
    // close popup 
    jQuery(".cross-link").on('click',function(){
		jQuery(".block-ipwa-search").removeClass('is-visible');
		
		
	});

	





	
});