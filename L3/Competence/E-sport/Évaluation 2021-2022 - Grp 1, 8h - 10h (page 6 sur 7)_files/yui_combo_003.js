YUI.add("moodle-core-formchangechecker",function(r,e){var c=function(){c.superclass.constructor.apply(this,arguments)};r.extend(c,r.Base,{initialvaluelisteners:[],initializer:function(){var e="form#"+this.get("formid"),t=r.one(e);t&&(M.core_formchangechecker.stateinformation.formchanged||(M.core_formchangechecker.stateinformation.formchanged=this.get("initialdirtystate")),r.on(M.core.event.EDITOR_CONTENT_RESTORED,M.core_formchangechecker.reset_form_dirty_state,this),t.delegate("change",M.core_formchangechecker.set_form_changed,"input",this),t.delegate("change",M.core_formchangechecker.set_form_changed,"textarea",this),t.delegate("change",M.core_formchangechecker.set_form_changed,"select",this),this.initialvaluelisteners.push(t.delegate("focus",this.store_initial_value,"input",this)),this.initialvaluelisteners.push(t.delegate("focus",this.store_initial_value,"textarea",this)),this.initialvaluelisteners.push(t.delegate("focus",this.store_initial_value,"select",this)),t.delegate("click",function(){t.setData("ignoreSubmission",!0)},"[data-formchangechecker-ignore-submit]"),r.one(e).on("submit",function(){t.getData("ignoreSubmission")?t.clearData("ignoreSubmission"):M.core_formchangechecker.set_form_submitted()},this),window.onbeforeunload=M.core_formchangechecker.report_form_dirty_state)},store_initial_value:function(e){if(!e.target.ancestor(".ignoredirty",!0)&&!e.target.ancestor("[data-formchangechecker-ignore-dirty]",!0))if(M.core_formchangechecker.get_form_dirty_state())for(;this.initialvaluelisteners.length;)this.initialvaluelisteners.shift().detach();else M.core_formchangechecker.stateinformation.focused_element={element:e.target,initial_value:e.target.get("value")}}},{NAME:"core-formchangechecker",ATTRS:{formid:{value:""},initialdirtystate:{value:!1}}}),M.core_formchangechecker=M.core_formchangechecker||{},M.core_formchangechecker.instances=M.core_formchangechecker.instances||[],M.core_formchangechecker.init=function(e){var t=new c(e);return M.core_formchangechecker.instances.push(t),t},M.core_formchangechecker.stateinformation=[],M.core_formchangechecker.set_form_changed=function(e){e&&e.target&&(e.target.ancestor(".ignoredirty",!0)||e.target.ancestor("[data-formchangechecker-ignore-dirty]",!0))||(M.core_formchangechecker.stateinformation.formchanged=1,delete M.core_formchangechecker.stateinformation.focused_element)},M.core_formchangechecker.set_form_submitted=function(){M.core_formchangechecker.stateinformation.formsubmitted=1},M.core_formchangechecker.get_form_dirty_state=function(){var e,t=M.core_formchangechecker.stateinformation;if(t.formsubmitted)return 0;if(t.formchanged)return 1;if(t.focused_element&&t.focused_element.element.get("value")!==t.focused_element.initial_value)return 1;if("undefined"!=typeof window.tinyMCE)for(e in window.tinyMCE.editors)if(window.tinyMCE.editors[e].isDirty())return 1;return 0},M.core_formchangechecker.reset_form_dirty_state=function(){M.core_formchangechecker.stateinformation.formsubmitted=!1,M.core_formchangechecker.stateinformation.formchanged=!1},M.core_formchangechecker.report_form_dirty_state=function(e){if(M.core_formchangechecker.get_form_dirty_state()){var t=M.util.get_string("changesmadereallygoaway","moodle");if(!M.cfg.behatsiterunning)return e&&(e.returnValue=t),t}}},"@VERSION@",{requires:["base","event-focus","moodle-core-event"]});