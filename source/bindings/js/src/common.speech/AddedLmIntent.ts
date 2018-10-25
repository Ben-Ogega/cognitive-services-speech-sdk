//
// copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license201809 for the full license information.
//

import { LanguageUnderstandingModelImpl } from "../sdk/LanguageUnderstandingModel";

/**
 * @class AddedLmIntent
 */
// tslint:disable-next-line:max-classes-per-file
export class AddedLmIntent {
    public modelImpl: LanguageUnderstandingModelImpl;
    public intentName: string;

    /**
     * Creates and initializes an instance of this class.
     * @constructor
     * @param modelImpl - The model.
     * @param intentName - The intent name.
     */
    public constructor(modelImpl: LanguageUnderstandingModelImpl, intentName: string) {
        this.modelImpl = modelImpl;
        this.intentName = intentName;
    }
}