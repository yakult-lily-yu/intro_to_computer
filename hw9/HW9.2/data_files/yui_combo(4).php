YUI.add("moodle-local_tdmmodatcursor-modatcursor",function(e,t){var n=e.namespace("M.local_tdmmodatcursor.modatcursor");n.formatString=function(t,n){return e.Object.each(n,function(e,n){t=t.replace("{"+n+"}",e)}),t},n.handleEvent=function(e){var t=e.currentTarget,n=e.type;switch(n){case"mouseover":this.showButtons(t);break;case"mouseout":e.relatedTarget&&e.relatedTarget.get("id").substr(0,8)==="section-"&&this.hideButtons()}},n.hideButtons=function(){this.top.all("."+this.params.listItemClass).remove(!0)},n.init=function(t){var n={course:null,activitySelector:".activity",sectionSelector:".section",topElement:".course-content",baseUrl:"/local/tdmmodatcursor/index.php?add={mod}&course={course}&section={section}&addabove={addabove}",buttonClass:"modatcursor-button",listItemClass:"modatcursor-listitem",modules:{}};this.params=e.merge(n,t),this.top=e.one(this.params.topElement);if(!e.one("body").hasClass("editing"))return;if(this.params.course===null)throw"Course ID must be specified";this.setupHandlers()},n.setupHandlers=function(){this.top.delegate("mouseover",this.handleEvent,this.params.activitySelector,this),this.top.delegate("mouseout",this.handleEvent,this.params.sectionSelector,this)},n.showButtons=function(t){if(t.one("."+this.params.listItemClass)!==null)return;this.hideButtons();var n=t.one(".menubar"),r=t.get("id").substr(7),i=t.ancestor(".section").ancestor(".section").get("id").substr(8);e.Object.each(this.params.modules,function(t){var s,o,u;o=M.cfg.wwwroot+this.formatString(this.params.baseUrl,{addabove:r,course:this.params.course,section:i,mod:t}),s=e.Node.create('<a href="'+o+'">'+M.util.get_string("addmod","local_tdmmodatcursor",M.util.get_string("modulename",t))+"</a>"),u=e.Node.create("<li></li>"),s.set("data-section",i),s.addClass(this.params.buttonClass),u.addClass(this.params.listItemClass),u.append(s),n.prepend(u)},this)}},"@VERSION@",{requires:["base","node-event-delegate"]});