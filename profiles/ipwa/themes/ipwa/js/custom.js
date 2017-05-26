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
		jQuery(this).addClass('active');
        jQuery('.block-ipwa-search').addClass('is-visible');
    });
    
    // close popup 
    jQuery(".cross-link").on('click',function(){
		jQuery(".search-icon").removeClass('active');
		jQuery(".block-ipwa-search").removeClass('is-visible');
		
		
	});
	
	// Copyright for video block single view
	
	if(jQuery(document).find(".field-name-field-videounterschrift").length > 0){
		var copyText1 = jQuery(".field-name-field-videoquelle .field-label").text(), 
		copyText2 = jQuery(".field-name-field-videoquelle .field-items .field-item").text(), 
		copyText = copyText1 + copyText2;
		jQuery(".field-name-field-videounterschrift .field-item").append("<span class='copyright'> " + copyText + "</span>");
		jQuery(".field-name-field-videoquelle").hide();
	}


	


	// header-mobile-menu
	
	if(jQuery(window).innerWidth() < 1025){
	
	jQuery(".navbar-toggle").click(function(){
		jQuery(".navbar-collapse").toggle();	
			});
		
		
		jQuery(".navbar-nav").insertAfter(".region-navigation");
jQuery('.tb-megamenu-submenu.dropdown-menu').attr('style','display:none !important');		
		 jQuery("ul.tb-megamenu-nav li a").click(function(){	
			 jQuery(this).next(".tb-megamenu-submenu").attr('style','display:block !important');
			jQuery(this).parent().siblings().find(".tb-megamenu-submenu").attr('style','display:none !important');
			jQuery(this).parent().siblings().removeClass("open");
		}); 
	};

    jQuery(function() {
        var pop_up_id;
        jQuery('div.pop-up').hide();
        jQuery('a.trigger').hover(function() {
            pop_up_id = this.id;
            pop_up_id = pop_up_id.substring(8);
            jQuery('div#pop-up-' + pop_up_id).show();
        }, function() {
            pop_up_id = this.id;
            pop_up_id = pop_up_id.substring(8);
            jQuery('div#pop-up-' + pop_up_id).hide();
        });
    });


	
});