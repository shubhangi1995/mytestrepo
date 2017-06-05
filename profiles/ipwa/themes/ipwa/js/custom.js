


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
		jQuery(this).toggleClass("active");
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
	
	// Calendar view work
	
	jQuery(".date-display-recurring").parent().addClass("recurring");
	jQuery(".date-display-single").parent().addClass("single");
	
	// Mouse over functionality
	
	jQuery(".date-box td").on("mouseover", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("greyHover");
		jQuery(this).parent().next(".single-day").find("td:eq(" +positionTD+ ")").addClass("greyHover")
	}).on("mouseout", function(){
		jQuery("table tr td").removeClass("greyHover");
	});
	
	
	jQuery(".single-day td").on("mouseover", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("greyHover");
		jQuery(this).parent().prev(".date-box").find("td:eq(" +positionTD+ ")").addClass("greyHover")
	}).on("mouseout", function(){
		jQuery("table tr td").removeClass("greyHover");
	});
	
	
	// Click functionality
	
	jQuery(".date-box td").on("click", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("redHover");
		jQuery(this).siblings().removeClass("redHover");
		jQuery(this).parent().siblings().find("td").removeClass("redHover");
		jQuery(this).parent().next(".single-day").find("td:eq(" +positionTD+ ")").addClass("redHover")
	});/*.on("mouseout", function(){
		if(!jQuery(this).parent().siblings().find("td:eq(" +positionTD+ ")").is(".redHover")){
			jQuery("table tr td").removeClass("redHover");
		}
	}); */
	
	jQuery(".single-day td").on("click", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("redHover");
		jQuery(this).siblings().removeClass("redHover");
		jQuery(this).parent().siblings().find("td").removeClass("redHover");
		jQuery(this).parent().prev(".date-box").find("td:eq(" +positionTD+ ")").addClass("redHover")
	});/*.on("mouseout", function(){
		if(!jQuery(this).parent().siblings().find("td:eq(" +positionTD+ ")").is(".redHover")){
			jQuery("table tr td").removeClass("redHover");
		}
	}); */
	
	/* jQuery(window).click(function(event){
		if(!jQuery(event.target).is(".redHover")){
			jQuery("table tr td").removeClass("redHover");
		}
	}); */

	
	// Calendar tool-tip
	
	jQuery(".single-day td .trigger").mouseover(function(){
		var toolId = jQuery(this).attr("id"), toolTipBox;
		jQuery(".view-event-on-calendar .view-content .views-row").each(function(index, element){
			var tipId = jQuery(element).find(".field-content .row-container").attr("id");
			if(toolId == tipId){
				//jQuery(this).parent().append(jQuery(element));
				toolTipBox = jQuery(element).clone();
			}
		});
		if(!jQuery(this).next().is(".views-row")){
			jQuery(this).parent().append(toolTipBox);
		}
		
		// Sensible mouseover tool tip
		if(jQuery(this).parents("td").is(":last-child, :nth-last-child(2)")){
			jQuery(this).next(".views-row").addClass("rightBorder");
		}
		
	});
	
	// Click on trigger
	
	jQuery(".single-day td .trigger").click(function(event){
		event.preventDefault();
	});
	
	// Structural changes
	
	jQuery(".page-calendar .calendar-link").insertAfter(jQuery("#edit-term-node-tid-depth-wrapper"));
	var monthText = jQuery(".page-calendar .date-views-pager h3").text();
	jQuery(".page-calendar .date-views-pager .pagination .prev").after("<li class='monthText'>" +monthText+ "</li>");
	jQuery(".page-calendar .date-views-pager").insertAfter(jQuery(".page-calendar .view-filters .calendar-link"));
	jQuery(".date-views-pager, .views-widget-sort-by").wrapAll("<div>");
	

	 jQuery(".page-taxonomy-term .view-alles-zum-thema .view-sub-wrapper .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by .bef-select-as-links .form-type-bef-link:first-child a").addClass("active");

	jQuery("#page_print").click(function(){
		window.print();
	});
	
});


