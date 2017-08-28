


jQuery(document).ready(function(){

//orientation changes for slider page only
	 if(jQuery(".view-wahlen-sie-einen-themenbereich").length){
		//console.log("right track");
		window.addEventListener('orientationchange', function () {
		   window.location.reload();
		});
	} 
  

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
	
	jQuery("#views-exposed-form-projekt-map-project-map select").select2({
		
		minimumResultsForSearch: Infinity
	});
	
	jQuery("#views-exposed-form-projekt-map-page-1 select").select2({
		
		minimumResultsForSearch: Infinity
	});
	
	
	jQuery("input:radio").each(function(){
	  if(jQuery(this).is(':checked')){
		jQuery(this).parent("label").css('border-bottom', '2px solid #e74712');
	  }
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
	
	
	// Calendar view
	
	/* jQuery(".page-calendar .view-content .calendar-calendar .inner .item .calendar span a").on("focus", function(){
		jQuery(this).mouseover();
		// jQuery(this).hover();
		jQuery(this).next(".views-row").attr("style", "display:block !important;");
		jQuery(this).parents("td, tr").siblings().find(".trigger").mouseout();
		jQuery(this).parents("td, tr").siblings().find(".trigger").next(".views-row").removeAttr("style");
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
		// jQuery(this).next().show();
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
	
	if(jQuery(window).innerWidth() <= 1024){
		jQuery(".nrw-eu-logo a").insertAfter(jQuery(".navbar-header .navbar-btn"));
	
	
		jQuery("header .container .navbar-collapse .region-navigation .tb-megamenu ul.tb-megamenu-nav li > a").click(function(){
			 jQuery('html, body').animate({
				scrollTop: jQuery(this).offset().top
			  },600); 
			
		});
		
	}
	
	jQuery(".block-ipwa-newsletter .form-submit").insertAfter(".block-ipwa-newsletter .form-item-newsletter .form-control");
	
	// Add to calendar link
	
	jQuery(".addtocalendar").appendTo(jQuery(".group-left-top-wrapper .group-middle-wrapper"));
	
	//footer icons//
	
	jQuery(".footer .footer_blocks").insertAfter(".footer .region-footer .block-menu");
	
	//termine view
	jQuery(".view-termin .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by").appendTo(".view-termin .attachment-before");
	
	//view-aktuelles
	jQuery(".view-aktuelles .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by").appendTo(".view-aktuelles .attachment-before");
	
	//view-search-list
	jQuery(".view-search-list .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by").appendTo(".view-search-list .attachment-before");
	
	//view-alles-zum-thema
	
	jQuery(".view-alles-zum-thema .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by").appendTo(".view-alles-zum-thema .attachment-before");
	
	// Share link tab indexing
	
	jQuery("#block-addthis-addthis-block a").attr("href", "");
	
	// Label tabs
	
	jQuery(".form-type-radio label, .search-icon, #backtotop").attr("tabindex", "0");
	
	// On enter key press
	jQuery(".form-type-radio label, .search-icon").keypress(function (e) {
		 var key = e.which;
		 if(key == 13)  // the enter key code
		  {
			jQuery(this).click();
			// Search input
			jQuery("#edit-search-text").focus();
			return false;  
		  }
	});
	
	// On enter key press upon back to top
	jQuery("#backtotop").keypress(function (e) {
		 var key = e.which;
		 if(key == 13)  // the enter key code
		  {
			jQuery("html, body").animate({scrollTop: 0}, 600); 
		  }
	});
	
	// Tab accessibility
	
	jQuery(".tb-megamenu .nav > li > a").on('focus', function(){
		jQuery(this).mouseover();
		jQuery(this).parent().siblings().find("a").mouseout();
	});
	
	// Tabbed drop downs list view
	
	jQuery(".select2-selection--single").on('focus', function(){
		jQuery(this).parents(".views-exposed-widget").addClass("focused");
		jQuery(this).parents(".views-exposed-widget").siblings().removeClass("focused");
	});
	
	jQuery(".select2-selection--single").on('blur', function(){
		if(jQuery(this).parents(".views-exposed-widget").is(":last-child")){
			jQuery(this).parents(".views-exposed-widget").removeClass("focused");
		}
	});
	
	// Outline for blue boxes
	
	jQuery(".project-blue, .front .view-termin .view-sub-wrapper .row-container").parent().on("focus", function(){
		jQuery(this).attr("style", "outline:2px dotted #e74712 !important;")
		// jQuery(this).parent(".views-row").siblings().find("a").attr("style", "outline:0;")
	});
	
	jQuery(".project-blue, .front .view-termin .view-sub-wrapper .row-container").parent().on("blur", function(){
		jQuery(this).attr("style", "outline:0;")
		/* if(jQuery(this).parent(".views-row").is(":last-child")){
			jQuery(this).attr("style", "outline:0;");
		} */
	});
	
	// Newsletter validations
	
	jQuery("#ipwa-newsletter-block-form #edit-submit--2").click(function(){
		var newsEmail = /^[A-Z0-9._%+-]+@([A-Z0-9-]+\.)+[A-Z]{2,4}$/i, newsValue = jQuery("#edit-newsletter").val();
		jQuery(this).parent().find(".error").remove();
		if(newsValue == ""){
			jQuery(this).parent().append("<div class='error'>Eine E-mail Adresse ist erforderlich</div>");
			return false;
		}
		else if(!newsEmail.test(newsValue)){
			jQuery(this).parent().append("<div class='error'>Verwenden Sie eine gültige E-Mail Adresse</div>");
			return false;
		}
		else{
			return true;
		}
	});
	
	// Calendar tool tip appearacnce work for responsive
	if(jQuery(window).innerWidth() <= 768){
		jQuery(".trigger").mouseover(function(e){
				e.stopPropagation();
				jQuery(this).next().show();
				jQuery(this).parents(".item, td, tr").siblings().find(".trigger + .views-row").hide();
				jQuery('.calendar-calendar').animate({
					scrollLeft: 0
				}, 0);
				if(jQuery(this).parents("tr").is(":last-child, :nth-last-child(2)")){
					jQuery('.calendar-calendar').animate({
						scrollTop: jQuery(this).offset().top - 200,
						scrollLeft: jQuery(this).offset().left - 150
					}, 500);	
				}
				else{
					jQuery('html, body').animate({
						scrollTop: jQuery(this).offset().top - 200,
					}, 500);
					jQuery('.calendar-calendar').animate({
						scrollLeft: jQuery(this).offset().left - 150
					}, 500);	
				}
		});
	}
	
	//page-projekt-map
	
	if(jQuery(".view-display-id-project_map").length > 0){
		jQuery(document.body).addClass("page-projekt-map");
	} 
	jQuery(".page-projekt-map .map-sub-title" ).appendTo(".page-projekt-map #map_list_link");
	
	jQuery(".page-projekt-map .paragraphs-item-topic-teaser-paragraph").parent().wrapAll("<div class='map-wrap'></div>");
	
	
	jQuery(".page-projekt-map .group-page-info .page-title , .page-projekt-map .group-page-info .field-name-body").wrapAll("<div class='project-map-wrapper'></div>");
	
	if(jQuery(window).innerWidth() > 1024){
	jQuery(".view-display-id-project_map .view-filters .views-submit-button").appendTo(".view-display-id-project_map .view-filters .categories-filter .views-widget-filter-search_api_aggregation_2");
	}
	
	// Akteur field display
	jQuery(document).on('mouseup', '.select2-container--open .select2-results__option', function (e) {
		if(jQuery('#edit-type-wrapper .select2-selection .select2-selection__rendered').html() == "Akteur"){
			jQuery(".views-widget-filter-field_akteurstyp").addClass("active");
		}
		else if (jQuery('#edit-type-wrapper .select2-selection .select2-selection__rendered').html() !== "Akteur"){
			jQuery(".views-widget-filter-field_akteurstyp").removeClass("active");
			jQuery("#edit-field-akteurstyp option").removeAttr('selected');
			jQuery("#edit-field-akteurstyp-wrapper .select2-selection__rendered").text("Akteur");
		}
	});
	
	// Akteur if selected
	if(jQuery("#edit-type option:selected").html() == "Akteur"){
		jQuery("#edit-field-akteurstyp-wrapper").addClass("active");
	}
	else if (!jQuery("#edit-field-akteurstyp option:selected").val() == "All") {
		jQuery("#edit-field-akteurstyp-wrapper").addClass("active");
	}
	
	jQuery(".view-display-id-page_1 .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by").appendTo(".view-display-id-page_1 .attachment-before");
	
	//page-projekt-map-list
	
	if(jQuery(".view-display-id-page_1").length > 0){
		jQuery(document.body).addClass("page-projekt-map-list");
	} 

	jQuery(".page-projekt-map-list .group-page-info .page-title , .page-projekt-map-list .group-page-info .field-type-text-with-summary").wrapAll("<div class='project-map-wrapper'></div>");

	jQuery(".page-projekt-map-list .paragraphs-item-topic-teaser-paragraph").parent().wrapAll("<div class='map-wrap'></div>");

	if(jQuery(window).innerWidth() > 1024){
	jQuery(".view-display-id-page_1 .view-filters .views-submit-button").appendTo(".view-display-id-page_1 .view-filters .categories-filter .views-widget-filter-search_api_aggregation_2");
	}
	// scrollbar for page-aktuelles

	jQuery('.page-aktuelles select, .page-projekt-map select, .page-projekt-map-list select').select2().on("select2:open", function(){
	 jQuery('.page-aktuelles .select2-results, .page-projekt-map .select2-results, .page-projekt-map-list .select2-results').addClass("simplebar");
	 jQuery('.page-aktuelles .select2-results, .page-projekt-map .select2-results, .page-projekt-map-list .select2-results').simplebar();
	});

	jQuery(window).click(function(event){
			jQuery(".views-exposed-widget").removeClass("selColor");
	});

	jQuery(".select2").on("click", function(event){
		// alert("hiee");
		event.stopPropagation();
		jQuery(this).parents(".views-exposed-widget").addClass("selColor").siblings().removeClass("selColor");
		if(!jQuery(this).next().is(".select2-container")){
			jQuery(this).parent().append(jQuery(".select2-dropdown").parent());
			jQuery(this).next().attr("style","top:29px !important;left:0 !important;");		
		}	
	});
	
	//header flyout ubersicht link
	if(jQuery(window).innerWidth() > 1024){
		jQuery('.tb-megamenu ul.tb-megamenu-nav li .mega-dropdown-inner .tb-submenu-left ul li:contains(Übersicht)').addClass("homelink");
	}

	//header flyout ubersicht for responsive view
	if(jQuery(window).innerWidth() < 1024){
		jQuery(".tb-megamenu-column-inner ul").each(function(index, element){
			jQuery(element).prepend(jQuery(element).find("li:contains(Übersicht)"));
		});
	} 

	// Page termine and calendar view
	jQuery(".page-calendar .page-header, .page-termine .page-header").before("<div class='calendar-icon'></div>");
	jQuery(".page-calendar .page-header, .page-termine .page-header").after(jQuery(".view-termin > .view-sub-wrapper > .view-header, .view-event-calendar > .view-sub-wrapper > .view-header"));
	jQuery(".page-calendar .page-header, .page-termine .page-header, .calendar-icon, .page-header + .view-header").wrapAll("<div class='container-new'></div>");
	jQuery(".calendar-icon").nextAll().wrapAll("<div class ='calendar-right'></div>");
	
	// customization in views slider for responsiveness
	
	/* jQuery(window).resize(function(){
		var totalHeight, viewSingleHeight;
		var viewWidth = jQuery(window).innerWidth() - 40;
		alert(viewWidth);
		jQuery(".views-slideshow-cycle-main-frame-row").each(function(index, element){
			if(jQuery(element).children().length  == 4){
				alert("i am four");
				jQuery(element).children().each(function(index, element){
					viewSingleHeight = jQuery(element).innerHeight();
					alert(viewSingleHeight);
					totalHeight += viewSingleHeight;
				});
				alert(totalHeight);
				
			}
		});
		jQuery(".views-slideshow-cycle-main-frame").css({width:viewWidth, height:1440});
	}); */

	
	if(jQuery(window).innerWidth() <= 1024){
		jQuery(".view-display-id-project_map .project-webform").insertAfter(".view-display-id-project_map  #map_list_link");
		
		
	}
	
	
});


