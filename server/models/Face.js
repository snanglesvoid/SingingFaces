var keystone = require('keystone');
var Types    = keystone.Field.Types;

/**
 * Face Model / aka Preset
 */

var Face = new keystone.List('Face', {
    autokey : { path:'slug', from:'name', unique:true },
    track : { createdAt:true, createdBy:true, updatedAt:true, updatedBy:true }
});


Face.add({
    user            : { type: Types.Relationship, ref: 'User', index: true },
    name            : { type: String, required: true, index: true },
    //about           : { type: Types.Markdown, height: 100 },
    plays           : { type: Types.Number, default: 0 },
    image           : { type: Types.CloudinaryImage },
    fml             : { type: Types.Code, height: 200, language: 'xml' },
    status          : { type: Types.Select, options: 'reported, rejected, active' },
    location        : { type: Types.Location }, //supports multiple inputs
    language        : { type: String, default: 'en-US' } // for more specific localization
});

//registration
Face.register();
